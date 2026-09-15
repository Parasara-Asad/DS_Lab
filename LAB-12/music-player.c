#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char name[100];
    struct Song* next;
    struct Song* prev;
};

struct Song* head = NULL;
struct Song* current = NULL;

void addSong(char* name) {
    struct Song* newSong = (struct Song*)malloc(sizeof(struct Song));
    strcpy(newSong->name, name);
    newSong->next = NULL;
    newSong->prev = NULL;
    
    if (head == NULL) {
        head = newSong;
        current = head;
        return;
    }
    
    struct Song* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newSong;
    newSong->prev = temp;
}

void playNext() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
        printf("Playing: %s\n", current->name);
    } else {
        printf("End of playlist.\n");
    }
}

void playPrev() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
        printf("Playing: %s\n", current->name);
    } else {
        printf("Start of playlist.\n");
    }
}

void displayPlaylist() {
    struct Song* temp = head;
    printf("\nPlaylist:\n");
    while (temp != NULL) {
        if (temp == current) {
            printf("-> %s\n", temp->name);
        } else {
            printf("   %s\n", temp->name);
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    addSong("Song 1");
    addSong("Song 2");
    addSong("Song 3");
    
    displayPlaylist();
    
    if(current != NULL) {
        printf("Playing: %s\n", current->name);
    }
    
    playNext();
    playNext();
    playPrev();
    
    return 0;
}
