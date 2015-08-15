from setuptools import setup, Extension

lyra2re_hash_module = Extension('lyra2re_hash',
                                sources = ['lyra2remodule.c',
                                          'lyra2re.c',
                                          '../../sph/blake.c',
                                          '../../sph/keccak.c',
                                          '../../sph/skein.c',
                                          '../../sph/groestl.c',
                                          '../../lyra2/Lyra2.c',
                                          '../../lyra2/Sponge.c'],
                                include_dirs=['.', '../../sph', '../../lyra2'])

setup (name = 'lyra2re_hash',
       version = '1.0',
       description = 'Bindings for proof of work used by DoomCoin',
       test_suite = 'test',
       ext_modules = [lyra2re_hash_module])
