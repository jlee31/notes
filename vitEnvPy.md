# working with virtual environments in python

https://www.youtube.com/watch?v=KxvKCSwlUv8&t=3s

allows us to separate the depencices of one project from another

when you switch virtual environments, you use different versions of libraries

you can make python libraries with python3.3 or later


path = Find path to python installation

Run in the command prompt/Terminal: path -m venv venvName

venv is a folder 

### Activate the virtual environment
source venvName/bin/Activate

if you pip installed while in the virtual environment, the library wouldbe installed inside the Scripts within the venv. 

### When making projects, you should have a virutal environment
Have stuff like requirements.txt which stores the name of the librraies
requirements-dev.txt
example:
    flask==1.0.0
    requests>=2.2.2,<2.0
    gunicorn
use
``` bash
pip install -r requirements.txt 
pip install -r requirements-dev.txt
```

