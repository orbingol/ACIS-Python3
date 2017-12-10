"""
    Examples for the Python 3 wrapper module for Spatial Corporation's 3D ACIS Modeler

    ACIS and SAT are registered trademarks of Spatial Corporation.

    The Python module is developed by Onur R. Bingol and released under MIT license.
    Please see the LICENSE file for details.
"""

from ACIS import utilities as utils
from ACIS import Modeler, Licensing, SaveRestore, Entity, Lists, GeometricAtoms, Sweeping, Query

# Start ACIS Modeler
Modeler.api_start_modeller(0)

# Unlock ACIS Modeler components
unlock_key = utils.read_spa_license_key("license.txt")
Licensing.spa_unlock_products(unlock_key)

# Make a cuboid
block = Entity.BODY()
Modeler.api_make_cuboid(150, 75, 25, block)

# Get faces of the cuboid
face_list = Lists.ENTITY_LIST()
Query.api_get_faces(block, face_list)

# Choose any face from the cuboid's face list
block_face = face_list.first()

# Convert the chosen face into a sheet body
sheet_body = Entity.BODY()
Modeler.api_sheet_from_ff([block_face], sheet_body)

# Make a sweep path
pt1 = GeometricAtoms.SPAposition(0.0, 0.0, 0.0)
pt2 = GeometricAtoms.SPAposition(10.0, 55.0, 23.0)
sweep_path = Entity.EDGE()
Sweeping.api_make_sweep_path([pt1, pt2], sweep_path)

# Sweep the chosen face using the sweep path
opts = Sweeping.sweep_options()
swept_body = Entity.BODY()
Sweeping.api_sweep_with_options(sheet_body, sweep_path, opts, swept_body)

# Assign attributes after generation
sheet_body.name = "Swept FACE"
sheet_body.id = 1

# Prepare for saving
save_list = Lists.ENTITY_LIST()
# api_sweep_with_options will modify sheet_body object as defined in its documentation
save_list.add(sheet_body)

# Set file name
filename = "ACIS_Ex03.SAT"

# ACIS requires FileInfo object to be set before saving SAT files
file_info = SaveRestore.FileInfo()
file_info.set_product_id(filename)
file_info.set_units(1.0)  # milimeters

SaveRestore.api_set_file_info(file_info, product_id=True, units=True)

# Save the model as a SAT file
SaveRestore.api_save_entity_list(filename, True, save_list)

# Stop ACIS Modeler
Modeler.api_stop_modeller()
