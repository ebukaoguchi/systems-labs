# Installing QtSpim for MIPS32

QtSpim is the MIPS32 simulator used in SCIS 216. Install it before the first assembly lab and test it by loading and running a short `.s` file.

Download QtSpim from the SPIM simulator project on SourceForge:

https://sourceforge.net/projects/spimsimulator/files/

## macOS

1. Download QtSpim for macOS (the `.dmg` file).
2. Open the `.dmg`, then drag `QtSpim.app` into **Applications**.
3. Launch QtSpim.
4. If macOS blocks the app, right-click it and choose **Open**, then **Open** again. You can also use **System Settings → Privacy & Security → Open Anyway**.
5. In QtSpim, choose **File → Reinitialize and Load File…** to open your `.s` file.
6. Choose **Run → Go**, or use the run/play button.

## Windows

1. Download the Windows installer or zip file.
2. Install or extract it, then run QtSpim.
3. Choose **File → Reinitialize and Load File…** to open your `.s` file.
4. Choose **Run → Go**.

## Linux (Ubuntu/Debian)

```bash
sudo apt update
sudo apt install qtspim
qtspim
```

## Common problems

- **“Label defined twice”**: choose **File → Reinitialize** and make sure only one program file is loaded and assembled.
- **Text or Data window looks wrong or is missing**: use the **Window** menu to show the window again.
- **The current QtSpim version is not compatible with your computer**: return to the SourceForge files page and try an older version.

## Used by

- First Contact with the Machine: MIPS Assembly and Machine Code in QtSpim
- Inside the ALU: Adders, Multipliers, and Dividers
- Build a MIPS Assembler: From Assembly to Machine Code
