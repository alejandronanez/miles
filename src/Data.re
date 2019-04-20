type airport = {
  id: int,
  name: string,
  city: option(string),
  country: string,
  iata: option(string),
  icao: option(string),
  latitude: float,
  longitude: float,
  altitude: int,
  timezone: option(string),
  dst: option(string),
  tz: option(string),
  kind: string,
  source: string,
};

type airports = Js.Dict.t(airport);

let parseAirportJson = json =>
  Json.Decode.{
    id: field("id", int, json),
    name: field("name", string, json),
    city: field("city", optional(string), json),
    country: field("country", string, json),
    iata: field("iata", optional(string), json),
    icao: field("icao", optional(string), json),
    // Used Json.Decode to avoid naming collisions with `float`
    latitude: field("latitude", Json.Decode.float, json),
    longitude: field("longitude", Json.Decode.float, json),
    altitude: field("altitude", int, json),
    timezone: field("timezone", optional(string), json),
    dst: field("dst", optional(string), json),
    tz: field("tz", optional(string), json),
    kind: field("kind", string, json),
    source: field("source", string, json),
  };

let parseAirportsJson = json => Json.Decode.(dict(parseAirportJson, json));

let fetchAirports = () => {
  Bs_fetch.fetch("/data.json")
  |> Js.Promise.then_(Bs_fetch.Response.text)
  |> Js.Promise.then_(jsonText =>
       jsonText |> Js.Json.parseExn |> parseAirportsJson |> Js.Promise.resolve
     );
};