#define _GNU_SOURCE
#include <dlfcn.h>
#include <libinput.h>

typedef const char *(*orig_get_name_t)(struct libinput_device *device);

const char *libinput_device_get_name(struct libinput_device *device)
{
    libinput_device_config_tap_set_enabled(device, LIBINPUT_CONFIG_TAP_ENABLED);
    orig_get_name_t orig_get_name;
    orig_get_name = (orig_get_name_t) dlsym(RTLD_NEXT, "libinput_device_get_name");
    return orig_get_name(device);
}
