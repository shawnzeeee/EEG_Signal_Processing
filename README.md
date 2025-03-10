# EEG_Signal_Processing

#data collection from eeg device
#artifact removal via ICA (python or MATLAB)
#Feature extraction to input vector
#Trained Neural Network for identifying closed/open

# Data Acquisition Setup

The program must compile to an ARM assembly executable to run on a beagle bone.

First establish connection with beagle bone. Refer to [NFS Guide](https://opencoursehub.cs.sfu.ca/bfraser/grav-cms/cmpt433/guides/files_byai/NFSGuide.pdf) and [Networking Guide](https://opencoursehub.cs.sfu.ca/bfraser/grav-cms/cmpt433/guides/files_byai/Networking.pdf). If everything is setup then follow these steps when booting up.

- On host run ./internetToTarget.sh

* Connect to beaglebone with

```
ssh username@192.168.7.2
```

- On target run ./internetToTarget.sh

* Go to your /mnt/remote directory and establish nfs with your host with. Use your path.

```
sudo mount -t nfs 192.168.7.1:/home/shawn/ensc351/public /mnt/remote
```

- To crosscompile go to the project directory into DataAcquisition and run 'make' to build and 'make clean' to clean object files
