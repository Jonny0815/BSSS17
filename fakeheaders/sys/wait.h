#pragma once

// fake header for visual studio

pid_t wait(int *status);

pid_t waitpid(pid_t pid, int *status, int options);
