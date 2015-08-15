from unittest import TestCase
import urlparse
import dcrypt_hash
import weakref
import binascii
import StringIO

from binascii import unhexlify, hexlify


class Test(TestCase):

    def test_powhash(self):
        teststart = '700000005d385ba114d079970b29a9418fd0549e7d68a95c7f168621a314201000000000578586d149fd07b22f3a8a347c516de7052f034d2b76ff68e0d6ecff9b77a45489e3fd511732011df0731000';
        testbin = unhexlify(teststart)
        hash_bin = dcrypt_hash.getPoWHash(testbin)
        print hexlify(hash_bin);
        self.assertEqual(hash_bin, unhexlify('25c3208eec754b936736d5377726d52d38ac5dee3b4f7345d204123d5bc87a29'))
