# libinput-force-tap-to-click

Force libinput to enable Tap-to-click for touchpad.  This allows Wayland compositors (that do not
expose libinput configuration) to configure the existing libinput functionality.

## Installation

Build `hook.so` then configure `libinput` to `LD_PRELOAD` it:

```bash
make
echo 'export LD_PRELOAD="$LD_PRELOAD /path/to/hook.so"' | sudo tee -a /etc/profile.d/libinput.sh
```

Log out and log in to enable.

## References

* [libinput documentation](https://wayland.freedesktop.org/libinput/doc/latest/tapping.html)
* Inspired by [middle-click-emulation](https://github.com/gaul/libinput-force-middle-click-emulation)

## License

* MIT
