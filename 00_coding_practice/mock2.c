/*you're writing firmware for a secure device. Each user has a permissions byte — each bit (0 to 7) represents a specific permission (like read/write/execute/admin, etc).
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t permissions;  // Each bit = one permission
} AccessControl;

void set_permission(AccessControl* ctrl, uint8_t bit);
void clear_permission(AccessControl* ctrl, uint8_t bit);
bool has_permission(const AccessControl* ctrl, uint8_t bit);
void toggle_permission(AccessControl* ctrl, uint8_t bit);

void set_permission(AccessControl* ctrl, uint8_t bit)
{
    ctrl->permissions |=1U<<bit;
}

void clear_permission(AccessControl* ctrl, uint8_t bit)
{
    ctrl->permissions &=~(1U<<bit);
}

bool has_permission(const AccessControl* ctrl, uint8_t bit){
    return (ctrl->permissions&(1U<<bit)) !=0;
}

void toggle_permission(AccessControl* ctrl, uint8_t bit){
    ctrl->permissions ^=(1U<<bit);
}

int main(){
    AccessControl user = {0};

    // Initially all bits should be 0
    printf("Has bit 3? %s\n", has_permission(&user, 3) ? "YES" : "NO");
    
    // Set bit 3
    set_permission(&user, 3);
    printf("After set bit 3: %s\n", has_permission(&user, 3) ? "YES" : "NO");
    
    // Toggle bit 2
    toggle_permission(&user, 2);
    printf("After toggle bit 2: %s\n", has_permission(&user, 2) ? "YES" : "NO");
    
    // Clear bit 3
    clear_permission(&user, 3);
    printf("After clear bit 3: %s\n", has_permission(&user, 3) ? "YES" : "NO");
    
    // Toggle bit 2 again
    toggle_permission(&user, 2);
    printf("Toggle bit 2 again: %s\n", has_permission(&user, 2) ? "YES" : "NO");
    return 0;
}