# `auto-init`

Automatically initialize the GHC RTS by calling `hs_init` (and deinitialize it by calling `hs_exit`) when your library loads, using GCC constructors and destructors.

## How to use

**`auto-init` is not yet published on Hackage**, but when it is, it will be as simple as adding `auto-init` to the `build-depends` field of your `foreign-library` stanza.

## Limitations

Since there is no portable way to get the program's arguments list in a constructor, the RTS is simply initialized with a nulled out argc and argv. This means that the results of `getProgName` and `getArgs` are likely to be `"<unknown>"` and `[]`, but importantly also means that the default RTS options are used. If you feel it's important to set the RTS options to something specific for your project, I recommend copying [`cbits/auto_init.c`](cbits/auto_init.c) into your own project, modifying it, and adding it to `extra-source-files` and `c-sources`. This really is a very simple library.

It should be noted that if `hs_init` has already been called by the running application that even if you set your own RTS opts as described above, the original invocation's options will still supersede yours. Subsequent inits are [simply ignored](https://github.com/ghc/ghc/blob/24d373a69c17d11da42c7fdc93efd4c17bd3f2c7/rts/RtsStartup.c#L248-L251).
