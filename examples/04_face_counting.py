"""
    Examples for the Python 3 wrapper module for Spatial Corporation's 3D ACIS Modeler

    ACIS and SAT are registered trademarks of Spatial Corporation.

    The Python module is developed by Onur R. Bingol and released under MIT license.
    Please see the LICENSE file for details.
"""

from ACIS import utilities as utils
from ACIS import Modeler

# Start ACIS Modeler
Modeler.api_start_modeller(0)

# Unlock ACIS Modeler components
unlock_key = utils.read_spa_license_key("license.txt")
Modeler.spa_unlock_products(unlock_key)

# Generate a truncated cone
frustum = Modeler.BODY()
Modeler.api_make_frustum(50, 20, 30, 10, frustum)

# Assign attributes after generation
frustum.name = "Truncated Cone"
frustum.id = 1

# Loop through the face list and print out the name of the entity type
face_list = Modeler.ENTITY_LIST()
Modeler.api_get_faces(frustum, face_list)

for f in face_list.array():
    fs = f.geometry()
    print(fs.type_name())

# Prepare for saving
save_list = Modeler.ENTITY_LIST()
save_list.add(frustum)

# Set file name
filename = "ACIS_Ex04.SAT"

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
