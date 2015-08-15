all hash (python) v1.0
===========================

Python modules for all hashing algorithms.

Algorithms
==========
#### Currently supported
 * ✓ __scrypt__ (Litecoin, Dogecoin, Feathercoin, ...)
 * ✓ __scrypt:N__
 * ✓ __sha256d__ (Bitcoin, Freicoin, Peercoin/PPCoin, Terracoin, ...)
 * ✓ __blake__ (Saffron [SFR] Blake-256)
 * ✓ __groestl__ (Groestlcoin)
 * ✓ __lyra2RE__ (Lyrabar, Cryptocoin)
 * ✓ __myr-groestl__ (Myriad-Groestl)
 * ✓ __nist5__ (MistCoin [MIC], TalkCoin [TAC], ...)
 * ✓ __pentablake__ (Joincoin)
 * ✓ __quark__ (Quarkcoin)
 * ✓ __qubit__ (MyriadCoin [MYR])
 * ✓ __skein__ (Skeincoin, Myriadcoin, Xedoscoin, ...)
 * ✓ __twe__ (TweCoin)
 * ✓ __whirlcoin__ (WhirlCoin)
 * ✓ __x11__ (Darkcoin [DRK], Hirocoin, Limecoin, ...)
 * ✓ __x13__ (Sherlockcoin, [ACE], [B2B], [GRC], [XHC], ...)
 * ✓ __x14__ (X14, Webcoin [WEB])
 * ✓ __x15__ (RadianceCoin [RCE])
 * ✓ __zr5__ (Ziftrcoin [ZRC])

#### Implemented, but untested
 * ? dcrypt
 * ? keccak (Maxcoin  HelixCoin, CryptoMeth, Galleon, 365coin, Slothcoin, BitcointalkCoin)
 * ? luffa (Joincoin, Doomcoin)
 * ? magi
 * ? yescrypt

Dependencies
------------
 * openssl libcrypto https://www.openssl.org/
 * python dev https://www.python.org/

Build
-----

    $ apt-get install python-all-dev debhelper
    $ debuild

Install one module by hand
--------------------------

Python 2.7 is required as well as a gcc.

    $ sudo python2 setup.py install

Test
-------

After installation, test hash.

    $ python2 setup.py test

Donations
---------

Donations for the work done in this repo are accepted:

elbandi <bandispam@gmail.com>
194EJLtVQK8Nac1qz3eWB131D3RTuTyiCB

Credits
-------


License
-------
MIT
