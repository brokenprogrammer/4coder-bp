/*
 * Mr. 4th Dimention - Allen Webster
 *
 * 24.03.2018
 *
 * History
 *
 */

// TOP

#if !defined(FRED_HISTORY_H)
#define FRED_HISTORY_H

struct Record_Batch_Slot{
    i32 length_forward;
    i32 length_backward;
    i32 first;
};

struct Record{
    Node node;
    Temp_Memory_Arena_Light restore_point;
    i32 edit_number;
    Record_Kind kind;
    union{
        struct{
            char *str_forward;
            char *str_backward;
            i32 length_forward;
            i32 length_backward;
            i32 first;
        } single;
        
        struct{
            Node children;
            i32 count;
        } group;
    };
};

struct Record_Ptr_Lookup_Table{
    Record **records;
    i32 count;
    i32 max;
};

struct History{
    b32 activated;
    Arena arena;
    Memory_Bank bank;
    Node free_records;
    Node records;
    i32 record_count;
    Record_Ptr_Lookup_Table record_lookup;
};

struct Global_History{
    i32 edit_number_counter;
    i32 edit_grouping_counter;
};

#endif

// BOTTOM
