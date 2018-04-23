
Debian
====================
This directory contains files used to package extnd/extn-qt
for Debian-based Linux systems. If you compile extnd/extn-qt yourself, there are some useful files here.

## extn: URI support ##


extn-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install extn-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your extnqt binary to `/usr/bin`
and the `../../share/pixmaps/extn128.png` to `/usr/share/pixmaps`

extn-qt.protocol (KDE)

