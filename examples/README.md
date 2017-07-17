# Scripts for Testing the Python Module

Please check the examples provided in this directory for details on how to use 3D ACIS Modeler and the Python module.

## Licensing

_3D ACIS Modeler_ requires a valid license key which can be obtained by contacting [Spatial Corporation](https://www.spatial.com/). After obtaining the license key, use the string value of the `unlock_str` variable to activate ACIS.

## Running Examples

An example on how to run the script from the command line:

`python3 -i 01_generate_solid_block.py`

This will leave you on the Python interpreter after executing the script (a.k.a. interactive mode). Therefore, you can test the code further in details.

Please note that if you would like to continue working with _3D ACIS Modeler_, please don't forget to comment out `Modeler.api_stop_modeller()` lines in the scripts. Otherwise, modeling operations will fail and the interpreter session might crash.
