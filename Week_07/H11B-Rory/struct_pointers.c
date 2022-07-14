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
	
	// Initialise 2 party members
	printf("First member: ");
	fgets(first_member.character_name, 100, stdin);
	printf("Second member: ");
	fgets(second_member.character_name, 100, stdin);
	
	first_member.weapon = fish;
	first_member.armor = overalls;
	
	second_member.weapon = no_weapon;
	second_member.armor = no_armor;
	
	// Swap gear of party members
	swap_gear(&first_member, &second_member);
	
	// Print success if swap was successful,
	// otherwise print failure
	if (
	    first_member.weapon == no_weapon &&
	    first_member.armor == no_armor &&
	    second_member.weapon == fish &&
	    second_member.armor == overalls
	) {
	    printf("success\n");
	} else {
	    printf("failure\n");
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

