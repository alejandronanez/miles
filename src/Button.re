[@react.component]
let make = (~onClick) => {
  <button type_="button" onClick>
    {ReasonReact.string("Get milleage!")}
  </button>;
};