/* Delete previous copy of config profile and save new one */
#include "e_wizard.h"

#if 0
EAPI int
wizard_page_init(E_Wizard_Page *pg __UNUSED__, Eina_Bool *need_xdg_desktops __UNUSED__, Eina_Bool *need_xdg_icons __UNUSED__)
{
   return 1;
}

EAPI int
wizard_page_shutdown(E_Wizard_Page *pg __UNUSED__)
{
   return 1;
}

EAPI int
wizard_page_show(E_Wizard_Page *pg __UNUSED__)
{
   return 0; /* 1 == show ui, and wait for user, 0 == just continue */
}

EAPI int
wizard_page_hide(E_Wizard_Page *pg __UNUSED__)
{
   return 1;
}
#endif

EAPI int
wizard_page_apply(E_Wizard_Page *pg __UNUSED__)
{
   #ifdef HAVE_ELEMENTARY
       e_util_set_bodhi_elm_config();
   #endif
   // save the config now everyone has modified it
   e_config_save();

   // disable restart env so we actually start a whole new session properly
   e_util_env_set("E_RESTART", NULL);
   
   // restart e
   e_sys_action_do(E_SYS_RESTART, NULL);

   e_util_open_bodhi_landing();
   return 1;
}

