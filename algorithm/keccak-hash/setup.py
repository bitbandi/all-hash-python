from setuptools import setup, Extension

keccak_hash_module = Extension('keccak_hash',
                               sources = ['keccakmodule.c',
                                          'keccak.c',
                                          '../../sph/keccak.c'],
                               include_dirs=['.', '../../sph'])

setup (name = 'keccak_hash',
       version = '1.0',
       description = 'Bindings for proof of work used by DoomCoin',
       test_suite = 'test',
       ext_modules = [keccak_hash_module])
