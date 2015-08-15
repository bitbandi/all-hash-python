from setuptools import setup, Extension

twe_hash_module = Extension('twe_hash',
                            sources = ['twemodule.c',
                                       'twe.c',
                                       '../../sph/fugue.c',
                                       '../../sph/hamsi.c',
                                       '../../sph/panama.c',
                                       '../../sph/shavite.c'],
                            include_dirs=['.', '../../sph'])

setup (name = 'twe_hash',
       version = '1.0',
       description = 'Bindings for proof of work used by DoomCoin',
       test_suite = 'test',
       ext_modules = [twe_hash_module])
