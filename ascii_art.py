
## first you need to install pyfiglet module
## Here is the pypip link of the module https://pypi.org/project/pyfiglet/

import pyfiglet # Now import the module
  
result = pyfiglet.figlet_format("Geeks", font = "banner3-D" ) # Now you can convert any string into ascii art
print(result)