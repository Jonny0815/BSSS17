#pragma once

#include "common.h"

// The writer thread
void writer( int writerID, int numSeconds );

// The reader thread
void reader( int readerID, int numSeconds );

void waittime();

