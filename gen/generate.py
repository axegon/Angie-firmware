import glob
import importlib
import os

import numpy as np


def main():
    """Storing the images as part of the firmware may be fast but they take
    a good chunk of space. So the hell with that, the microcontroller comes
    with an SD cart slot. This thingamajig will generate the images. All
    that's needed is to store them on the SD cart and load them up from there.
    For adding more images, see the readme."""
    files = glob.glob("*_img.py")
    if not os.path.exists("output"):
        os.makedirs("output")
    for filename in files:
        module_name = filename[:-3]
        module = importlib.import_module(module_name)
        img = getattr(module, "data", None)
        if isinstance(module.data, np.ndarray):
            img.tofile(f"output/{filename[:-7]}.bin")


if __name__ == "__main__":
    main()
