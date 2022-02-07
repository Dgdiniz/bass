![bass](doc/bass.svg)


# bass

bass is a table-based, multi-architecture and cross-platform, macro assembler developed by Near up until version 17.

This is the *v18* with adds a lot of new architectures and some improvements. Check the main repository: [https://github.com/ARM9/bass](https://github.com/ARM9/bass).

It is targeted at developers and hackers interested in legacy video game consoles such as the NES, SNES, MegaDrive and others.

**bass is for you if:**
  * you want or need to work low level
  * you want to avoid dependencies
  * you target obscure systems that lack any other compiler
  * you want to build your own compiler
  * you want extensive macro features giving you the convenience of a higher-level programming language
  * you want the ability to do root level debugging

**This is not for you if:**
  * you look for a higher 'real' programming language
  * you expect an complete toolchain that takes care about all your needs


## New Features

This repository adds some new features on top of the *v18* official version. The new features are:

- First version of the LSP (Language Server Protocol) feature. It should be used with Vim/Neovim (https://github.com/dgdiniz/bass-lsp).
- MOVEM instruction now accepts the register list format.

## Releases
Downloads can be found in the [Release Section](https://github.com/dgdiniz/bass/releases).


### Building
Bass requires the *gcc* compiler. For example *MingW 8.1.0* on Windows.
```
git clone https://github.com/ARM9/bass.git && cd bass/bass && make
```

## Documentation
  * Online [Handbook](doc/index.md)
