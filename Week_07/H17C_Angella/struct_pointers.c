// #include's, enum's and type declarations -----------------------------

#include <stdio.h>
#include <string.h>

enum weapon { 
    no_weapon, 
    big_sword, 
    little_sword, 
    wand, 
    fish 
};

enum armor { 
    no_armor, 
    knight_armor, 
    mage_robes, 
    overalls 
};

struct party_member {
    char character_name[100];
    // Gear:
    enum weapon weapon;
    enum armor armor;
};

// Function prototypes ---------------------------------------------------

void swap_gear(struct party_member *member1, struct party_member *member2);
void print_party_member(struct party_member member);

// Main function ---------------------------------------------------------

int main (void) {

    struct party_member luigi;
    strcpy(luigi.character_name, "Luigi Mario");
    luigi.weapon = big_sword;
    luigi.armor = knight_armor;

    struct party_member mario;
    strcpy(mario.character_name, "Mario Mario");
    mario.weapon = no_weapon;
    mario.armor = overalls;

    // Pass in the addresses of the structs `luigi` and `mario` so their
    // corresponding pointers will have their addresses.
    swap_gear(&luigi, &mario);

    print_party_member(luigi);
    print_party_member(mario);

}

// Helper functions -----------------------------------------------------

// Swaps the weapon and armor of member1 and member2
//TODO: Whats wrong with this code?
// - Modifying the structs without returning it is futile as changes will
//   not be reflected back to where the function was called.
// - Cannot return both structs, thus, use `struct party_member` pointers.
void swap_gear(struct party_member *member1, struct party_member *member2) {

    // When doing `*member2.armor`, the program reads it as `*(member2.armor)
    // which would give us error as you cannot dereference `member2.armor` as
    // it is not a pointer. 
    // Doing `(*member2).armor` is valid as it references the pointer first,
    // which gives us the struct, which then we can access the armor field
    // from it.
    // It is better to do `member2->weapon` as it does the same thing but it
    // is easier to type/read.
    enum armor temp_armor = (*member2).armor;
    enum weapon temp_weapon = member2->weapon;
    
    member2->armor = member1->armor;
    member2->weapon = member1->weapon;

    member1->armor = temp_armor;
    member1->weapon = temp_weapon;
}

/****************** UNIMPORTANT: just for printing ************************/

char *get_weapon_str(enum weapon weapon) {

    if (weapon == big_sword) {
        return "Big sword";
    } else if (weapon == little_sword) {
        return "Little sword";
    } else if (weapon == wand) {
        return "Wand";
    } else if (weapon == fish) {
        return "Fish";
    } else {
        return "No weapon";
    } 

}


char *get_armor_str(enum armor armor) {
    if (armor == knight_armor) {
        return "Knight armor";
    } else if (armor == mage_robes) {
        return "Mage robes";
    } else if (armor == overalls) {
        return "Overalls";
    } else {
        return "No armor";
    } 

}

void print_party_member(struct party_member member) {
    printf("%s\n", member.character_name);
    
    printf("weapon: %s\n", get_weapon_str(member.weapon));
    printf("armor:  %s\n\n", get_armor_str(member.armor));

}
