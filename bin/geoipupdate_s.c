
#include "geoipupdate.h"
#include <string.h>
#include <stdlib.h>

geoipupdate_s *geoipupdate_s_new(void)
{
    size_t size = sizeof(geoipupdate_s);
    geoipupdate_s *gu = xmalloc(size);
    memset(gu, 0, size);
    gu->license_file = xstrdup(SYSCONFDIR "/GeoIP.conf");
    gu->database_dir = xstrdup(DATADIR);
    gu->proto = xstrdup("https");
    gu->host = xstrdup("updates.maxmind.com");
    gu->proxy = xstrdup("");
    gu->proxy_user_password = xstrdup("");
    gu->verbose = 0;
    gu->license.user_id = NO_USER_ID;
    gu->license.license_key[12] = 0;
    return gu;
}

void geoipupdate_s_delete(geoipupdate_s * gu)
{
    if (gu) {
        product_delete_all(gu);
        free(gu->license_file);
        free(gu->database_dir);
        free(gu->proto);
        free(gu->proxy);
        free(gu->proxy_user_password);
        free(gu->host);
        free(gu);
    }
}

