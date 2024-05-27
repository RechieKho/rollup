#include "mechanism.hpp"

Mechanism::~Mechanism() {}

void Mechanism::setup() {}
void Mechanism::process(UInt p_delta) {}

void Mechanism::prepare_capture() {}
void Mechanism::capture() {}
void Mechanism::prepare_dispatch() {}
void Mechanism::dispatch() {}
void Mechanism::revert_dispatch() {}