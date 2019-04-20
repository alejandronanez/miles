let updateInput = (updaterFunction, event) =>
  updaterFunction(ReactEvent.Form.target(event)##value);
let handleButtonClick = _event => Js.log("clicked");

[@react.component]
let make = () => {
  let (origin, setOrigin) = React.useState(() => "");
  let (_airports, setAirports) = React.useState(() => None);
  let (destination, setDestination) = React.useState(() => "");

  React.useEffect0(() => {
    Data.fetchAirports()
    |> Js.Promise.then_(airportData => {
         /**
         Had to destructure the tuple b/c we're getting a tuple from the resolver
         instead of the plain result
         */
         let (_func, airportDataFromServer) = airportData;
         setAirports(_prevState => Some(airportDataFromServer));
         Js.Promise.resolve();
       })
    |> Js.Promise.catch(err => {
         Js.log("An error occurred: " ++ Js.String.make(err));
         Js.Promise.resolve();
       })
    |> ignore;
    Some(() => ());
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