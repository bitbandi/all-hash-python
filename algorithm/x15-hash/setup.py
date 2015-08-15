from setuptools import setup, Extension

x15_hash_module = Extension('x15_hash',
                            sources = ['x15module.c',
                                       'x15.c',
                                       '../../sph/blake.c',
                                       '../../sph/bmw.c',
                                       '../../sph/groestl.c',
                                       '../../sph/jh.c',
                                       '../../sph/keccak.c',
                                       '../../sph/skein.c',
                                       '../../sph/cubehash.c',
                                       '../../sph/echo.c',
                                       '../../sph/luffa.c',
                                       '../../sph/simd.c',
                                       '../../sph/hamsi.c',
                                       '../../sph/hamsi_helper.c',
                                       '../../sph/fugue.c',
                                       '../../sph/shavite.c',
                                       '../../sph/shabal.c',
                                       '../../sph/whirlpool.c'],
                            include_dirs=['.', '../../sph'])

setup (name = 'x15_hash',
       version = '1.0',
       description = 'Bindings for proof of work used by x15 hash',
       test_suite = 'test',
       ext_modules = [x15_hash_module])
