#include "finders.h"

#include <math.h>

int main(int argc, char* argv[]) {

    initBiomes();
    LayerStack g = setupGenerator(MC_1_15);
    // int *map = allocCache(&g.layers[g.layerNum - 1], 256, 256);

    int MCversion = 115;

    // int64_t seed = 159381538881525800;
    int64_t seed = -1614536902600909162;

    applySeed(&g, seed);

    // chunk coords into region coords - region is 32x32 of chunks - bit shift
    // int chunk_x = 962;
    // int chunk_z = -307;

    // int chunk_x = 32;
    // int chunk_z = -11;

    int chunk_x = -977;
    int chunk_z = 685;

    if (argc == 3) {
        chunk_x = atoi(argv[1]);
        chunk_z = atoi(argv[2]);
    }

    int region_x = chunk_x >> 5;
    int region_z = chunk_z >> 5;

    // should take in chunks
    Pos pos = getStructurePos(SWAMP_HUT_CONFIG, seed, region_x, region_z);
    // Pos pos_r = getStructureChunkInRegion(SWAMP_HUT_CONFIG, seed, region_x, region_z);

    // is viable takes coordiantes, not chunk
    int valid = isViableFeaturePos(Swamp_Hut, g, NULL, pos.x, pos.z);

    int biome = getBiomeAtPos(g, pos);

    printf("chunk (x, z): %d, %d\n", chunk_x, chunk_z);
    printf("region (x, z): %d, %d\n", region_x, region_z);
    printf("pos (x, z): %d, %d\n", pos.x, pos.z);
    printf("valid?: %d\n", valid);
    printf("biome (swamp=6): %d\n", biome); // swampland is 6



    int64_t *seed2 = malloc(sizeof(int64_t));
    *seed2 = -1614536902600909162;
    setStructureSeed(seed2, 25096, 68);
}