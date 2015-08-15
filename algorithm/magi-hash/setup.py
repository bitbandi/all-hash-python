from setuptools import Extension, setup

magi_hash_module = Extension('magi_hash',
                               sources = ['m7m_module.c',
                                          'm7m.c',
                                          'magimath.c',
                                          '../../sph/keccak.c',
                                          '../../sph/haval.c',
                                          '../../sph/ripemd.c',
                                          '../../sph/sha2.c',
                                          '../../sph/sha2big.c',
                                          '../../sph/tiger.c',
                                          '../../sph/whirlpool.c'
                                          ],
                               include_dirs=['.', '../../sph'],
                               libraries=['gmp'])

setup (name = 'magi_hash',
       version = '1.0',
       description = 'Bindings for scrypt proof of work used by Coin Magi',
       test_suite = 'test',
       ext_modules = [magi_hash_module])
