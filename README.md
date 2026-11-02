# Competitive programming

Open this repository folder in VS Code with the Microsoft C/C++ extension.
Install GNU GCC and put `g++` on your PATH (Homebrew GCC on macOS, GCC on Linux,
or MinGW-w64 GCC on Windows). Apple Clang does not provide `bits/stdc++.h`.

In a C++ file, type `!cp` and press Tab to insert the template with the cursor
inside `main`.

Use the C++ Run button or the `C++: run active file` launch configuration.
The default build shortcut (Cmd+Shift+B on macOS, Ctrl+Shift+B elsewhere) uses
the same build task. Debugging also requires LLDB on macOS or GDB on Linux/Windows.

All executables and debug symbols go into `.build/` at the repository root.
Source subfolders are preserved: `platforms/example.cpp` builds to
`.build/platforms/example` (`example.exe` on Windows). This location is the same
on every machine, and Git ignores the entire folder. VS Code configuration is
tracked with the project. Delete `.build/` at any time to clean generated files.
