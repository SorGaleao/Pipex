# 🎮 so_long

<div align="center">

  <img src="https://img.shields.io/badge/language-C-blue.svg" alt="Language">
  <img src="https://img.shields.io/badge/42-School-lightgrey.svg" alt="42 School">
  <img src="https://img.shields.io/badge/status-active-green.svg" alt="Status">

</div>

# Pipex

## 📜 About

A small Unix-like pipeline emulator written in C. The program executes two commands connected by a pipe, redirecting input from a file and output to a file.

## Overview

`pipex` receives four arguments and behaves similarly to the shell pipeline:

```
< infile cmd1 | cmd2 > outfile
```

It opens `infile`, executes `cmd1` whose stdin comes from `infile`, connects `cmd1`'s stdout to `cmd2`'s stdin using a pipe, and writes `cmd2`'s stdout into `outfile`.

The project uses a local `libft/` static library for utility functions; the top-level `Makefile` builds `libft` automatically.

## Requirements

- POSIX-compatible system (Linux, macOS)
- A C compiler (e.g. `cc`, `gcc`)

## Build

From the project root:

```sh
make
```

Useful targets:

- `make` — build `libft` and the `pipex` executable
- `make clean` — remove object files and `obj/` directory (also runs `libft` clean)
- `make fclean` — remove `pipex` executable and run `libft` fclean
- `make re` — `fclean` then `all`

The `Makefile` prints a short usage block after a successful build.

## Usage

```
./pipex infile "cmd1 [args]" "cmd2 [args]" outfile
```

Example:

```sh
./pipex infile "ls -l" "grep '.c'" outfile
```

Equivalent shell command:

```sh
< infile ls -l | grep '.c' > outfile
```

## How it works (brief)

- Create a pipe and fork two child processes.
- First child: redirect stdin from `infile`, redirect stdout to the pipe write-end, exec `cmd1`.
- Second child: redirect stdin from the pipe read-end, redirect stdout to `outfile`, exec `cmd2`.
- Parent waits for both children and frees resources.

## Notes

- `main` expects `envp` so commands can be located via `PATH`.
- `outfile` is opened with `O_CREAT | O_WRONLY | O_TRUNC` and mode `0644`.
- Ensure `infile` exists and that you have permissions to write `outfile`.

## Author

gabrsouz

## License

No license is included. Add one if you plan to publish or distribute this project.
