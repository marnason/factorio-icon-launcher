# Factorio Custom Launcher

A tiny Windows executable that launches `factorio.exe` from the same folder, using a custom icon. Drop it next to `factorio.exe` and use it as your shortcut target.

## Building

Requires Visual Studio 2022 Build Tools. Open the workspace in VS Code and run the default build task (`Ctrl+Shift+B`), or run it from the command line:

```
cmd /c "if not exist build mkdir build && "C:\Program Files\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat" && rc /nologo /fo "build\app.res" "res\app.rc" && cl /nologo /O2 /W4 /MT /Fe:"build\Factorio-Custom.exe" "src\main.c" "build\app.res" /link /SUBSYSTEM:WINDOWS"
```

## License

This is free and unencumbered software released into the public domain. See [UNLICENSE](UNLICENSE) for details.
