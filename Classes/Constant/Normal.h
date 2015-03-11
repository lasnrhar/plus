#ifndef __NORMAL_H__
#define __NORMAL_H__

const static int NORMAL_LEVEL = 10;

static int normalMap1[9][9] = { { 1, 0, 0, 1, 1, 1, 1, 1, 3 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 1, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 0, 1, 1, 1, 1, 1, 1 },
								{ 2, 1, 1, 1, 0, 0, 0, 1, 1 } };
static int normalValue1[9][9] = { { -9, 0, 0, 1, 2, 3, 3, 3, 3 },
								  { 1, 0, 2, 1, 2, 1, 0, 1, 2 },
								  { 1, 0, 1, 2, 1, 2, 0, 1, 1 },
								  { 1, 0, 2, 1, 2, 1, 0, 1, 1 },
								  { 1, 1, 1, 2, 1, 2, 0, 1, 1 },
								  { 1, 0, 2, 1, 2, 1, 0, 1, 1 },
								  { 1, 0, 1, 2, 1, 2, 0, 1, 1 },
								  { 1, 0, 0, 2, 2, 1, 1, 1, 2 },
								  { 2, 2, 3, 3, 0, 0, 0, 2, -5 } };

static int normalMap2[9][9] = { { 1, 1, 0, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 0, 1, 1, 1, 0, 0, 1 },
								{ 1, 0, 1, 1, 1, 1, 1, 0, 1 },
								{ 1, 1, 1, 1, 1, 1, 1, 1, 1 },
								{ 1, 1, 2, 1, 1, 1, 3, 1, 1 },
								{ 1, 1, 1, 1, 1, 1, 1, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 1, 0, 1 },
								{ 1, 0, 0, 1, 1, 1, 0, 0, 1 },
								{ 1, 1, 0, 1, 1, 1, 0, 1, 1 } };
static int normalValue2[9][9] = { { -4, -5, 0, 3, -5, 3, 0, -5, -2 },
								  { 2, 0, 1, 3, 4, 3, 1, 0, 2 },
								  { 1, 0, 1, 6, 8, 6, 1, 0, 1 },
								  { 1, 3, 1, 7, 8, 7, 1, 1, 1 },
								  { 1, 1, 2, 8, 9, 8, 3, 1, 1 },
								  { 1, 3, 1, 7, 8, 7, 1, 1, 1 },
								  { 1, 0, 1, 6, 8, 6, 1, 0, 1 },
								  { 2, 0, 0, 3, 4, 3, 0, 0, 2 },
								  { -4, -5, 0, 3, -5, 3, 0, -5, -2 } };

static int normalMap3[9][9] = { { 0, 0, 0, 0, 0, 0, 1, 0, 0 },
								{ 0, 0, 1, 1, 1, 1, 1, 0, 3 },
								{ 1, 1, 1, 1, 1, 1, 1, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 1, 0, 1 },
								{ 1, 0, 1, 1, 1, 1, 1, 0, 1 },
								{ 1, 1, 1, 1, 1, 1, 1, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 1, 0, 1 },
								{ 2, 0, 1, 1, 1, 1, 1, 0, 1 },
								{ 1, 1, 0, 0, 0, 0, 1, 1, 1 } };
static int normalValue3[9][9] = { { 0, 0, 0, 0, 0, 0, -3, 0, 0 },
								  { 0, 0, 2, 3, 2, 3, 2, 0, 3 },
								  { 1, 3, 3, 2, 3, 2, 3, 1, 1 },
								  { 1, 0, 1, 1, 1, 1, 1, 0, 1 },
							      { 1, 0, 1, 3, 3, 3, 1, 0, 1 },
								  { 1, 5, 1, 4, 4, 4, 1, 1, 1 },
								  { 1, 0, 1, 3, 3, 3, 1, 0, 1 },
								  { 2, 0, 1, 2, 2, 2, 2, 0, 1 },
								  { -9, -9, 0, 0, 0, 0, -5, 1, 1 } };

static int normalMap4[9][9] = { { 2, 1, 1, 1, 1, 1, 1, 1, 1 },
								{ 0, 0, 0, 0, 0, 0, 0, 0, 1 },
								{ 3, 0, 1, 1, 1, 1, 1, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 1, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 1, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 1, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 1, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 1, 1, 1 },
								{ 1, 1, 1, 0, 0, 0, 0, 1, 1 } };
static int normalValue4[9][9] = { { 2, 1, 1, 1, 1, 1, 1, 1, 1 },
								  { 0, 0, 0, 0, 0, 0, 0, 0, 1 },
								  { 3, 0, -5, 5, 1, 3, 1, 5, 1 },
								  { 1, 0, 1, 5, 1, 3, 1, 5, 1 },
								  { 1, 0, 1, 3, 1, 2, 1, 3, 1 },
								  { 1, 0, 1, 3, 1, 2, 1, 3, 1 },
								  { 1, 0, 1, 2, 1, 5, 1, 2, 1 },
								  { 1, 0, 1, 2, 1, 5, 1, 2, 1 },
								  { 1, 1, 1, 0, 0, 0, 0, 1, 1 } };

static int normalMap5[9][9] = { { 2, 0, 0, 1, 1, 0, 0, 1, 3 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 1, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 0, 1, 1, 1, 1, 1, 1 },
								{ 1, 1, 0, 0, 0, 0, 0, 1, 1 } };
static int normalValue5[9][9] = { { 1, 0, 0, 1, 1, 0, 0, 1, 3 },
								  { 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								  { 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								  { 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								  { 1, 1, 1, 1, 1, 1, 0, 1, 1 },
								  { 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								  { 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								  { 1, 0, 1, 1, 1, 1, 1, 1, 1 },
								  { 2, 0, 0, 0, 0, 0, 0, 1, 1 } };

static int normalMap6[9][9] = { { 2, 0, 0, 1, 1, 0, 0, 1, 3 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 1, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 0, 1, 1, 1, 1, 1, 1 },
								{ 1, 1, 0, 0, 0, 0, 0, 1, 1 } };
static int normalValue6[9][9] = { { 1, 0, 0, 1, 1, 0, 0, 1, 3 },
								  { 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								  { 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								  { 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								  { 1, 1, 1, 1, 1, 1, 0, 1, 1 },
								  { 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								  { 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								  { 1, 0, 1, 1, 1, 1, 1, 1, 1 },
								  { 2, 0, 0, 0, 0, 0, 0, 1, 1 } };

static int normalMap7[9][9] = { { 2, 0, 0, 1, 1, 0, 0, 1, 3 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 1, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 0, 1, 1, 1, 1, 1, 1 },
								{ 1, 1, 0, 0, 0, 0, 0, 1, 1 } };
static int normalValue7[9][9] = { { 1, 0, 0, 1, 1, 0, 0, 1, 3 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 1, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 1, 1, 1 },
								{ 2, 0, 0, 0, 0, 0, 0, 1, 1 } };

static int normalMap8[9][9] = { { 2, 0, 0, 1, 1, 0, 0, 1, 3 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 1, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 0, 1, 1, 1, 1, 1, 1 },
								{ 1, 1, 0, 0, 0, 0, 0, 1, 1 } };
static int normalValue8[9][9] = { { 1, 0, 0, 1, 1, 0, 0, 1, 3 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 1, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 1, 1, 1 },
								{ 2, 0, 0, 0, 0, 0, 0, 1, 1 } };

static int normalMap9[9][9] = { { 2, 0, 0, 1, 1, 0, 0, 1, 3 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 1, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 0, 1, 1, 1, 1, 1, 1 },
								{ 1, 1, 0, 0, 0, 0, 0, 1, 1 } };
static int normalValue9[9][9] = { { 1, 0, 0, 1, 1, 0, 0, 1, 3 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 1, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 1, 1, 1 },
								{ 2, 0, 0, 0, 0, 0, 0, 1, 1 } };

static int normalMap10[9][9] = { { 2, 0, 0, 1, 1, 0, 0, 1, 3 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 1, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 0, 1, 1, 1, 1, 1, 1 },
								{ 1, 1, 0, 0, 0, 0, 0, 1, 1 } };
static int normalValue10[9][9] = { { 1, 0, 0, 1, 1, 0, 0, 1, 3 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 1, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 0, 1, 1 },
								{ 1, 0, 1, 1, 1, 1, 1, 1, 1 },
								{ 2, 0, 0, 0, 0, 0, 0, 1, 1 } };

#endif