# ReaktorBug
3D printed government surveillance drone

Ein kleiner (~12x12cm) Roboter soll gebaut werden, der über das Internet durch den Space gefahren werden kann.

# Privacy
Der Bug sollte keine Leute oder kritische Sachen filmen können.
- Ideen:
  - Der Roboter sollte sich irgendwie™ automatisch ausschalten, wenn jemand da ist.
  - Hardware-Batterietrennschalter
  - Eigenen Bereich (Podest) einrichten.
- Umsetzung:

# Hardware
- AI Thinker ESP32-CAM
- 28BJY-48 Geared Stepper

# Software
- Soll mit ROS kompatibel sein
- [Link zu einer Library für ROS](https://github.com/dabmake/ESPROS)
- [Link zu einer Library für die Stepper](https://github.com/Stan-Reifel/TinyStepper_28BYJ_48/blob/master/Documentation.md)

# Berechnung
Bei angenommenen U<sub>max</sub> des Motors von 0,2 s<sup>-1</sup>:

D<sub>Rad</sub> [mm] | V<sub>max</sub> [mm/s] | Sekunden pro Meter
------------ | ------------- | -------------
25 | 15 | 66
30 | 19 | 52
35 | 22 | 45
40 | 25 | 40
45 | 28 | 36
50 | 30 | 33
