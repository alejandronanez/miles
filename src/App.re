let updateInput = (updaterFunction, event) =>
  updaterFunction(ReactEvent.Form.target(event)##value);

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
  </div>;
};