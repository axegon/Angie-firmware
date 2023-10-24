# Generating images dore the microcontroller's display.

1KB is 1KB, ain't gonna throw it away for no good reason. The scripts here will generate the images that will be stored on the sd card that goes into the esp32 module. In order to add more:

### 1. Prerequisites.

Python >= 3.6 and pip. Could be a virtualenvironment or conda or whatever you fancy, doesn't matter all that much. Run:

```
$ pip install -r requirements.txt
```

### 2. Create a new file, following the convention `somename_img.py`.

The filename should end with `_img.py`. The file should contain the following:

```
import numpy as np

data = np.array(
    [
...
    ]
).astype(np.uint8)

```

The numpy array should contain the values of each pixel in hexadecimal. [Special thanks to Jasper van Loenen for making people's lives easier](https://javl.github.io/image2cpp/).

### 3. Generate.

Run

```
$ python generate.py
```

Assume you have a file called `something_img.py`, which meets the requirements in the second step, the script will create a directory called output in the current directory, which will contain `something.bin`. That's it. Copy it over to the sd card, read it from there(or don't, I'm not your mom).
