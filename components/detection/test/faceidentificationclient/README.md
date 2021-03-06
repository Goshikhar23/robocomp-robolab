# FaceIdentificationClient

This component serves as a testing and monitoring component for `FaceIdentification` component. It first requests the RGB frames from `CameraSimple`, which it passes the images to `FaceIdentification` component to request detecting human faces and recognizing them by tagging.
Overall, the whole pipeline involves 3 components: `FaceIdentification`, `FaceIdentificationClient` and `CameraSimple`.

## Resolving dependencies

This section assumes the user has already installed the RoboComp core library and pulled Robolab's components according to this [README guide](https://github.com/robocomp/robocomp).

Before using the component, the user needs to install the necessary libraries:
```
pip install numpy opencv-python
```


## Configuration parameters
As an example, `FaceIdentificationClient` component parameters are characterized in config file described below:

```
# Proxies for required interfaces
FaceIdentificationProxy = faceidentification:tcp -h localhost -p 10008
CameraSimpleProxy = camerasimple:tcp -h localhost -p 10005


# This property is used by the clients to connect to IceStorm.
TopicManager.Proxy=IceStorm/TopicManager:default -p 9999


Ice.Warn.Connections=0
Ice.Trace.Network=0
Ice.Trace.Protocol=0
Ice.ACM.Client=10
Ice.ACM.Server=10

```

You must ensure the proxies' hostname and port number of `FaceIdentificationProxy` and `CameraSimpleProxy` match the endpoints in the config files of the corresponding interfaces.

## Starting the monitoring Emotion Recognition

To avoid changing the config file in the repository, we can copy it to the component's home directory, so changes will remain untouched by future git pulls:
```
cd ~/robocomp/components/robocomp-robolab/components/detection/test/faceidentificationclient/
cp etc/config etc/config-run
```

After editing the new config file we can run the component as follow:

```
cd robocomp/components/robocomp-robolab/components
```
Open 2 new terminals.

Terminal 1:
```
cd hardware/camera/camerasimple
python src/camerasimple.py etc/config-run
```

Terminal 2:
```
cd detection/faceidentification
python src/faceidentification.py etc/config-run
```

Terminal 3:
```
cd detection/test/faceidentificationclient
python src/faceidentificationclient.py etc/config-run
```

Now one can see the captured frames with a bounding box and person's name on top of the bounding box. Another popup window will open which allows the user to Add/Delete labels. One can also add an image directly from the camera feed and recognize faces in the images. Images are stored in the folder `robocomp/components/robocomp-robolab/components/detection/test/faceidentificationclient`.
