# Applications.
arduino:=arduino-cli
echo:=echo
rm:=rm -rf
grep:=grep

# Directories.
current_dir:=$(dir $(realpath $(lastword $(MAKEFILE_LIST))))

# Files.
project_file:=$(current_dir)project.env
local_project_file:=$(current_dir)project.env.local

# Options.
ifneq ($(wildcard $(project_file)),)
include $(project_file)
endif

ifneq ($(wildcard $(local_project_file)),)
include $(local_project_file)
endif

# Defaulted options.
PROJECT_NAME?=my_sketch
VERSION?=0.0.1
PACKAGER?=arduino
ARCH?=samd
MODEL?=mkr1000
DEPS?=
PORT?=

# Inference.
override DEFINES+=VERSION=$(VERSION)
fqbn:=$(PACKAGER):$(ARCH):$(MODEL)
output_folder:=$(PROJECT_NAME).dist.local
output_dir:=$(current_dir)$(output_folder)/
build_folder:=$(PROJECT_NAME).build.local
build_dir:=$(current_dir)$(build_folder)/
cache_folder:=$(PROJECT_NAME).cache.local
cache_dir:=$(current_dir)$(cache_folder)/
source_dir:=$(current_dir)$(PROJECT_NAME)/
source_files:=$(wildcard $(source_dir)*)


default: compiledb $(output_dir)
.PHONY: default

setup:
ifeq ($(shell $(arduino) core list --no-color --format text | $(grep) $(ARCH)),)
	$(info -- Installing board.)
	@$(arduino) core install $(PACKAGER):$(ARCH)
endif
	$(info -- Installing dependencies.)
	@$(foreach DEP,$(DEPS),$(if $(shell $(arduino) lib list --no-color --format text | $(grep) $(DEP)),,$(echo) "Installing '$(DEP)'.";$(arduino) lib install $(DEP);))
.PHONY: setup

upload: $(output_dir)
ifeq ($(PORT),)
	$(error !! Port is not given, unable to upload.)
endif
	@$(arduino) upload $< -b $(fqbn) -p $(PORT)
.PHONY: upload

compiledb: $(source_files) setup
	$(info -- Generating `compile_commands.json` into $(build_dir).)
	@$(arduino) compile -b "$(fqbn)" --build-property "build.extra_flags=\"$(DEFINES:%=-D%)\"" --only-compilation-database $(source_dir) 
.PHONY: compiledb

clean:
	$(info -- Clean generated files.)
	$(rm) $(output_dir) $(build_folder) $(cache_folder)
.PHONY: clean

$(output_dir): $(source_files) setup
	$(info -- Compiling project.)
	@$(arduino) compile -b "$(fqbn)" \
		--build-property "build.extra_flags=\"$(DEFINES:%=-D%)\"" \
		--output-dir $@ \
		--build-path $(build_dir) \
		--build-cache-path $(cache_dir) \
		$(source_dir)
