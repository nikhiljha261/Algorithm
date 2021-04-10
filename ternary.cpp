// if our graph shape is like u or v we can use ternary search 
// there are two mid
#define EPS 1e-6
double low = -1e6;
double high = 1e6;

// loop untill difference between low and high
// become less than EPS
while ((high - low) > EPS)
{
  // mid1 and mid2 are representative x co-ordiantes
  // of search space
  double mid1 = low + (high - low) / 3;
  double mid2 = high - (high - low) / 3;

  //
  double dist1 = compute(p, n, l, mid1);
  double dist2 = compute(p, n, l, mid2);

  // if mid2 point gives more total distance,
  // skip third part
  if (dist1 < dist2)
      high = mid2;

  // if mid1 point gives more total distance,
  // skip first part
  else
      low = mid1;
}

// compute optimum distance cost by sending average
// of low and high as X
return compute(p, n, l, (low + high) / 2);
