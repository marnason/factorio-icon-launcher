# factorio-icon-launcher

A tiny Factorio launcher with a high-resolution shortcut icon.

[Download the latest release](https://github.com/marnason/factorio-icon-launcher/releases/latest/download/factorio-icon-launcher.exe)

It simply launches `factorio.exe` from the same folder. Drop it next to `res/factorio.exe`, then point your shortcut at this launcher instead of the original executable.

<p align="center">
  <img src="factorio.ico" width="256" alt="Factorio custom launcher icon">
</p>

Inspired by this Factorio forum post:
https://forums.factorio.com/viewtopic.php?p=695765

## Building

Requires Visual Studio 2022 Build Tools. Open the workspace in VS Code and run the default build task (`Ctrl+Shift+B`), or run it from the command line:

```cmd
cmd /c "if not exist build mkdir build && "C:\Program Files\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat" && rc /nologo /fo "build\app.res" "res\app.rc" && cl /nologo /O2 /W4 /MT /Fe:"build\Factorio-Custom.exe" "src\main.c" "build\app.res" /link /SUBSYSTEM:WINDOWS"
```

## License

This is free and unencumbered software released into the public domain. See [UNLICENSE](UNLICENSE) for details.
