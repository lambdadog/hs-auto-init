# `hs-auto-init`

Automatically initialize the GHC RTS by calling `hs_init` (and deinitialize it by calling `hs_exit`) when your library loads, using GCC constructors and destructors.

## How to use

**`hs-auto-init` is not yet published on Hackage**, but when it is, it will be as simple as adding `hs-auto-init` to the `build-depends` field of your `foreign-library` stanza.
