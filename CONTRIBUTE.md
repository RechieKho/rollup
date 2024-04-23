# Rollup Contribution Guide

Welcome to this project!
Rollup project structure is based on [the `Ardu` project template](https://github.com/RechieKho/ardu),
that allows arduino programming beyond Arduino IDE.

### `Ardu` Guide

[`Ardu`](https://github.com/RechieKho/ardu) allows compilation and uploading arduino code
easily through `arduino-cli`, automated with `make`.

### Requirements

A unix-like environment with POSIX-compliant shell (such as `bash`),
together with these program available in `PATH`:

- `make`
- `arduino-cli`
- `echo`
- `rm`
- `grep`

### Project metadata

The project metadata are stored in `project.env` and `project.env.local` at the root of the project.
`project.env` is the generic project metadata while `project.env.local` override the metadata in `project.env`.

These are the fields to set:

- `PROJECT_NAME` - Name of the project. It must have the same name as the sketch file.
- `VERSION` - Version of the project.
- `PACKAGER` - Board's provider (e.g. `arduino`)
- `ARCH` - Board's architecture (e.g. `avr`)
- `MODEL` - Board's model (e.g. `uno`)
- `DEPS` - Space-seperated dependencies to be installed.
- `PORT` - Port of the target board to upload to.

### Command usages

- `make` - Compile the code and generate `compile_commands.json`.
- `make setup` - Install the board and dependencies.
- `make upload` - Setup, compile and upload to the targeted board on port `PORT`
- `make compiledb` - Generate `compile_commands.json`.
- `make clean` - Delete all the generated files. It does not delete installed board and dependencies
