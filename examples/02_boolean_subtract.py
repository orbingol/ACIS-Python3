"""
    Examples for the Python 3 wrapper module for Spatial Corporation's 3D ACIS Modeler

    ACIS and SAT are registered trademarks of Spatial Corporation.

    The Python module is developed by Onur R. Bingol and released under MIT license.
    Please see the LICENSE file for details.
"""

# This example is taken from the book "Rapid Prototyping and Engineering Applications" by Frank W. Liou (Example 5.1)

from ACIS import utilities as utils
from ACIS import Modeler

# Start ACIS Modeler
Modeler.api_start_modeller(0)

# Unlock ACIS Modeler components
unlock_key = utils.read_spa_license_key("license.txt")
Modeler.spa_unlock_products(unlock_key)

# Make a cuboid
block = Modeler.BODY()
Modeler.api_make_cuboid(150, 75, 25, block)

# Generate and apply transformation to the cuboid
block_vector = Modeler.SPAvector(0.0, 0.0, 12.7)
block_transf = Modeler.translate_transf(block_vector)
Modeler.api_apply_transf(block, block_transf)

# Make a frustum
cylinder = Modeler.BODY()
Modeler.api_make_frustum(19.05, 12.7, 12.7, 12.7, cylinder)

# Generate and apply transformation to the frustum
cylinder_vector = Modeler.SPAvector(0.0, 0.0, 6.35)
cylinder_transf = Modeler.translate_transf(cylinder_vector)
Modeler.api_apply_transf(cylinder, cylinder_transf)

# Subtract frustum from cuboid
Booleans.api_subtract(cylinder, block)

# Assign attributes after generation
block.name = "Drilled Cuboid"
block.id = 1

# Prepare for saving
save_list = Modeler.ENTITY_LIST()
save_list.add(block)

# Set file name
filename = "ACIS_Ex02.SAT"

# ACIS requires FileInfo object to be set before saving SAT files
file_info = Modeler.FileInfo()
file_info.set_product_id(filename)
file_info.set_units(1.0)  # milimeters

Modeler.api_set_file_info(file_info, product_id=True, units=True)

## Enable sequence numbers (i.e., pointers) in the SAT file for debugging (optional step)
#Modeler.api_set_int_option("sequence_save_files", 1)

# Save the model as a SAT file
Modeler.api_save_entity_list(filename, True, save_list)

# Stop ACIS Modeler
Modeler.api_stop_modeller()
