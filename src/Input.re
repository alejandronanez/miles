[@react.component]
let make = (~value, ~onChange, ~label, ~name) => {
  <div>
    <label htmlFor=name> {ReasonReact.string(label)} </label>
    <input type_="text" onChange id=name value />
  </div>;
};