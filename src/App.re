let updateInput = (updaterFunction, event) =>
  updaterFunction(ReactEvent.Form.target(event)##value);
let handleButtonClick = _event => Js.log("clicked");

// Helpers
let getMilesBetweenPoints = (~pointA, ~pointB) =>
  LeafletRe.LatLng.distanceTo(pointA, pointB) /. 1609.344;

// Dummy data
let bogota =
  LeafletRe.create_lat_lng(
    ~latitude=4.70159,
    ~longitude=-74.1469,
    ~altitude=Some(0.0),
  );
let miami =
  LeafletRe.create_lat_lng(
    ~latitude=25.79319953918457,
    ~longitude=-80.29060363769531,
    ~altitude=Some(0.0),
  );

Js.log(getMilesBetweenPoints(~pointA=bogota, ~pointB=miami));

[@react.component]
let make = () => {
  let (origin, setOrigin) = React.useState(() => "");
  let (destination, setDestination) = React.useState(() => "");

  <div>
    <Input
      value=origin
      onChange={updateInput(setOrigin)}
      label="Origin"
      name="origin"
    />
    <Input
      value=destination
      onChange={updateInput(setDestination)}
      label="Destination"
      name="destination"
    />
    <Button onClick=handleButtonClick />
  </div>;
};