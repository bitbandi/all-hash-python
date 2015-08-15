from setuptools import setup, Extension

skein_hash_module = Extension('skein_hash',
                               sources = ['skeinmodule.c',
                                          'skein.c',
                                          '../../sph/skein.c',
                                          '../../sph/sha2.c'],
                               include_dirs=['.', '../../sph'],
                               extra_compile_args=['-O1'])

setup (name = 'skein_hash',
       version = '1.0',
       description = 'Bindings for skein proof of work modified for Myriadcoin Skein',
       test_suite = 'test',
       ext_modules = [skein_hash_module])
