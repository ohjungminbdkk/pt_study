#include <stdio.h>
#include <stdlib.h>

typedef struct MemoryPool {
    void* pool;           // 메모리 풀의 시작 주소
    size_t block_size;    // 각 블록의 크기
    size_t block_count;   // 블록의 수

    size_t used_index; // 사용중인 블록 위치

} MemoryPool;

// 메모리 풀 생성 함수
MemoryPool* create_pool(size_t block_size, size_t block_count) {
    // (2) MemoryPool 구조체 메모리 할당
    MemoryPool* pool = (MemoryPool*)malloc(sizeof(MemoryPool));
    // (3) 실제 메모리 풀 공간 할당
    pool->pool = malloc(block_size * block_count);  // 블록 크기만큼 메모리 할당

    pool->block_size = block_size;
    pool->block_count = block_count;
    pool->used_index = 0;
    
    return pool;
}

// 메모리 풀에서 블록 할당 함수
void* allocate_block(MemoryPool* pool) {
    printf("시작주소 = %p\n", pool->pool);

    printf("블록size = %ld\n", pool->block_size);
    printf("pool = %p\n", pool->pool);
    printf("1번 블록 = %p\n", pool->pool);
    printf("2번 블록 = %p\n", (char*)pool->pool + pool->block_size);  // 주소값의 +128
    printf("3번 블록 = %p\n", (char*)pool->pool + 2 * pool->block_size);  // 주소값의 +(2*(128))
    // 1번 블록 = 0x5e271ed1e2c0
    // 2번 블록 = 0x5e271ed1e340 (+0x80 (+128))
    // 3번 블록 = 0x5e271ed1e3c0 (+0x80 (+128))   
    
    if (pool->used_index >= pool->block_count) {
        return NULL;
    }
    void* addr = (char*)pool->pool + (pool->used_index * pool->block_size);
    pool->used_index++;
    // (4) 메모리 풀의 첫 번째 블록 주소 반환
    //return pool->pool;  // 메모리 풀의 첫 번째 블록을 반환
    return addr;
}

// 메모리 풀에서 블록 반환 함수
void free_block(MemoryPool* pool) {
    // 메모리 풀의 첫 번째 블록을 반환하는 방법은 상황에 맞게 수정 가능
    // 현재 예시에서는 간단히 구현
}

// 메모리 풀 삭제 함수
void destroy_pool(MemoryPool* pool) {
    free(pool->pool);  //(5) 할당된 메모리 풀 메모리 해제
    free(pool);        //(6) 메모리 풀 구조체 메모리 해제
    pool=NULL;
}

int main() {
    // (1) 메모리 풀 생성
    MemoryPool* pool = create_pool(128, 10);  // 128 바이트 크기의 블록 10개

    printf("pool= %p\n", pool);
    // (4) 메모리 블록 할당
    void* block = allocate_block(pool);
    int* b_val = (int*) block;
    *b_val = 100;

    printf("Memory Block Allocated at: %p\n", block);
    printf("1번 할당된 블록= %p\n", block);
    printf("1번 할당된 b_val블록= %p\n", b_val);
    printf("1번 할당된 b_val값= %d\n", *b_val);


    void* block2 = allocate_block(pool);
    int* b_val2 = (int*) block2;
    *b_val2 = 222;

    printf("2번 할당된 블록= %p\n", block2);
    printf("2번 할당된 b_val블록= %p\n", b_val2);
    printf("2번 할당된 b_val값= %d\n", *b_val2);


    // (5) 메모리 풀 삭제
    destroy_pool(pool);
    printf("destroy_pool 후\n");
    printf("pool= %p\n", pool);
    printf("1번 할당된 블록= %p\n", block);
    printf("1번 할당된 b_val블록= %p\n", b_val);
    printf("1번 할당된 b_val값= %d\n", *b_val);
    printf("2번 할당된 블록= %p\n", block2);
    printf("2번 할당된 b_val블록= %p\n", b_val2);
    printf("2번 할당된 b_val값= %d\n", *b_val2);

    //계속 확인중
    return 0;
}

//https://ko.ittrip.xyz/c/c-language-memory-pool-implementation