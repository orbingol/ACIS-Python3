"""
    Helper Functions for the Python 3 wrapper module for Spatial Corporation's 3D ACIS Modeler

    ACIS and SAT are registered trademarks of Spatial Corporation.

    The Python module is developed by Onur R. Bingol and released under MIT license.
    Please see the LICENSE file for details.
"""

import re


def read_spa_license_key(filename=''):
    regex_seq = re.compile(r'\s?\"(.*)\"')

    license_text = ""
    search_obj = None

    try:
        with open(filename, 'r') as fp:
            license_code = fp.read()
            search_obj = regex_seq.finditer(license_code.strip())
            fp.close()
    except IOError:
        raise IOError('Cannot open file: ' + filename)

    if search_obj:
        for line in search_obj:
            license_text = license_text + line.group(1)
    else:
        raise ValueError('The file "' + filename + '" does not contain the unlock key!')

    return license_text
