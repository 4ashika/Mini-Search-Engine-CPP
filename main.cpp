#include "minisearch.h"

int main()
{
  MiniSearch engine;
  // Make sure you have a folder named 'datasets' with some .txt files!
  engine.loadDatasets("./datasets");
  return 0;
}
