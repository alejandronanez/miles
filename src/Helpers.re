// Helpers
let getMilesBetweenPoints = (~pointA, ~pointB) =>
  LeafletRe.LatLng.distanceTo(pointA, pointB) /. 1609.344;

// Bogota
let start =
  LeafletRe.create_lat_lng(
    ~latitude=4.70159,
    ~longitude=-74.1469,
    ~altitude=Some(0.0),
  );

// Miami
let finish =
  LeafletRe.create_lat_lng(
    ~latitude=25.79319953918457,
    ~longitude=-80.29060363769531,
    ~altitude=Some(0.0),
  );

/**
Js.log(getMilesBetweenPoints(~pointA=start, ~pointB=finish));
*/;