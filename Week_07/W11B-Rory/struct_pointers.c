#include <stdio.h>

enum weapon { no_weapon, big_sword, little_sword, wand, fish };
enum armor { no_armor, knight_armor, mage_robes, overalls };

struct party_member {
    char character_name[100];

    // Gear:
    enum weapon weapon;
    enum armor armor;
};

void swap_gear(struct party_member *member1, struct party_member *member2);

int main(void) {
	struct party_member first_member;
	struct party_member second_member;
	
	printf("First member: ");
	fgets(first_member.character_name, 100, stdin);
	printf("Second member: ");
	fgets(second_member.character_name, 100, stdin);
	
	first_member.weapon = fish;
	first_member.armor = overalls;
	
	second_member.weapon = no_weapon;
	second_member.armor = no_armor;
	
	swap_gear(&first_member, &second_member);
	
	// Realistically want to check all fields for success but
	// this is done for the interest of time.	
	if (first_member.weapon == no_weapon) {
	    printf("success\n");
	} else {
	    printf("failed\n");
	}
	return 0;
}

// Swaps the weapon and armor of member1 and member2
void swap_gear(struct party_member *member1, struct party_member *member2) {
    enum armor temp_armor = member2->armor;
    enum weapon temp_weapon = member2->weapon;
    
    member2->armor = member1->armor;
    member2->weapon = member1->weapon;

    
    member1->armor = temp_armor;
    member1->weapon = temp_weapon;
}
