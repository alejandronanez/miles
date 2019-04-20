let updateInput = (updaterFunction, event) =>
  ReactEvent.Form.target(event)##value->updaterFunction;
let handleButtonClick = _event => Js.log("clicked");

[@react.component]
let make = () => {
  let (origin, setOrigin) = React.useState(() => "");
  let (_airports, setAirports) = React.useState(() => None);
  let (destination, setDestination) = React.useState(() => "");

  React.useEffect0(() => {
    Data.fetchAirports()
    |> Js.Promise.then_(airportData => {
         setAirports(_prevState => Some(airportData));
         Js.Promise.resolve();
       })
    |> Js.Promise.catch(err => {
         Js.log("An error occurred: " ++ Js.String.make(err));
         Js.Promise.resolve();
       })
    |> ignore;

    None;
  });

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