
#!/usr/bin/env python
# Generated by pykdeuic4 from analog_clock_config.ui on Sun Sep 14 13:02:52 2008
#
# WARNING! All changes to this file will be lost.
from PyKDE4 import kdecore
from PyKDE4 import kdeui
from PyQt4 import QtCore, QtGui

class Ui_clockConfig(object):
    def setupUi(self, clockConfig):
        clockConfig.setObjectName("clockConfig")
        clockConfig.resize(400, 300)
        clockConfig.setMinimumSize(QtCore.QSize(400, 300))
        self.vboxlayout = QtGui.QVBoxLayout(clockConfig)
        self.vboxlayout.setObjectName("vboxlayout")
        self.vboxlayout1 = QtGui.QVBoxLayout()
        self.vboxlayout1.setObjectName("vboxlayout1")
        self.groupBox = QtGui.QGroupBox(clockConfig)
        self.groupBox.setFlat(True)
        self.groupBox.setObjectName("groupBox")
        self.vboxlayout2 = QtGui.QVBoxLayout(self.groupBox)
        self.vboxlayout2.setObjectName("vboxlayout2")
        self.vboxlayout3 = QtGui.QVBoxLayout()
        self.vboxlayout3.setObjectName("vboxlayout3")
        self.showSecondHandCheckBox = QtGui.QCheckBox(self.groupBox)
        self.showSecondHandCheckBox.setObjectName("showSecondHandCheckBox")
        self.vboxlayout3.addWidget(self.showSecondHandCheckBox)
        self.showTimeStringCheckBox = QtGui.QCheckBox(self.groupBox)
        self.showTimeStringCheckBox.setObjectName("showTimeStringCheckBox")
        self.vboxlayout3.addWidget(self.showTimeStringCheckBox)
        self.vboxlayout2.addLayout(self.vboxlayout3)
        self.vboxlayout1.addWidget(self.groupBox)
        self.groupBox_2 = QtGui.QGroupBox(clockConfig)
        self.groupBox_2.setFlat(True)
        self.groupBox_2.setObjectName("groupBox_2")
        self.vboxlayout4 = QtGui.QVBoxLayout(self.groupBox_2)
        self.vboxlayout4.setObjectName("vboxlayout4")
        self.vboxlayout5 = QtGui.QVBoxLayout()
        self.vboxlayout5.setObjectName("vboxlayout5")
        self.localTimeZone = QtGui.QCheckBox(self.groupBox_2)
        self.localTimeZone.setObjectName("localTimeZone")
        self.vboxlayout5.addWidget(self.localTimeZone)
        self.timeZones = KTimeZoneWidget(self.groupBox_2)
        self.timeZones.setMinimumSize(QtCore.QSize(300, 150))
        self.timeZones.setObjectName("timeZones")
        self.vboxlayout5.addWidget(self.timeZones)
        self.vboxlayout4.addLayout(self.vboxlayout5)
        self.vboxlayout1.addWidget(self.groupBox_2)
        self.vboxlayout.addLayout(self.vboxlayout1)

        self.retranslateUi(clockConfig)
        QtCore.QMetaObject.connectSlotsByName(clockConfig)

    def retranslateUi(self, clockConfig):
        self.groupBox.setTitle(kdecore.i18n("Appearance"))
        self.showSecondHandCheckBox.setToolTip(kdecore.i18n("Show the seconds"))
        self.showSecondHandCheckBox.setWhatsThis(kdecore.i18n("Check this if you want to show the seconds."))
        self.showSecondHandCheckBox.setText(kdecore.i18n("Show &seconds"))
        self.showTimeStringCheckBox.setToolTip(kdecore.i18n("Show the time in text"))
        self.showTimeStringCheckBox.setWhatsThis(kdecore.i18n("Check this if you want to show the time as a text within the clock."))
        self.showTimeStringCheckBox.setText(kdecore.i18n("Also show the time in text"))
        self.groupBox_2.setTitle(kdecore.i18n("Timezones"))
        self.localTimeZone.setText(kdecore.i18n("Use &local timezone"))
        self.timeZones.headerItem().setText(0, kdecore.i18n("Area"))
        self.timeZones.headerItem().setText(1, kdecore.i18n("Region"))
        self.timeZones.headerItem().setText(2, kdecore.i18n("Comment"))

from PyKDE4.kdeui import KTimeZoneWidget
